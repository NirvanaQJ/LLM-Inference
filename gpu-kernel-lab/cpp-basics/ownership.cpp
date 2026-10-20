#include <iostream>
#include <memory>
#include <utility>

struct Request {
    int id = 7;

    ~Request() {
        std::cout << "销毁请求\n";
    }
};

void unique_demo() {
    auto req = std::make_unique<Request>();

    {
        auto next = std::move(req);
        std::cout << "处理请求 " << next->id << "\n";
    }

    if (!req) {
        std::cout << "req 已空\n";
    }
}

void weak_demo() {
    std::weak_ptr<Request> watch;

    {
        auto req = std::make_shared<Request>();
        watch = req;

        std::cout << "强引用数 " << req.use_count() << "\n";
        std::cout << "块内过期 " << watch.expired() << "\n";

        if (auto current = watch.lock()) {
            std::cout << "访问请求 " << current->id << "\n";
        }
    } // A

    std::cout << "块外过期 " << watch.expired() << "\n";

    if (auto current = watch.lock()) {
        std::cout << "访问请求 " << current->id << "\n";
    } else {
        std::cout << "请求已不存在\n";
    }
}

struct CycleRequest {
    int id = 0;
    std::shared_ptr<CycleRequest> peer;

    ~CycleRequest() {
        std::cout << "销毁请求 " << id << "\n";
    }
};

// 循环引用演示：观察完成后手动断环清理。
void cycle_demo() {
    std::weak_ptr<CycleRequest> watch_a;
    std::weak_ptr<CycleRequest> watch_b;

    {
        auto a = std::make_shared<CycleRequest>();
        auto b = std::make_shared<CycleRequest>();
        a->id = 1;
        b->id = 2;

        a->peer = b; // 请求 1 拥有请求 2。
        b->peer = a; // 请求 2 拥有请求 1。

        watch_a = a;
        watch_b = b;

        std::cout << "块内计数 " << a.use_count()
                  << " " << b.use_count() << "\n";
    }

    std::cout << "块外计数 " << watch_a.use_count()
              << " " << watch_b.use_count() << "\n";
    std::cout << "块外过期 " << watch_a.expired()
              << " " << watch_b.expired() << "\n";

    std::cout << "开始手动断环\n";
    if (auto saved = watch_a.lock()) {
        saved->peer.reset();
    }

    std::cout << "清理后过期 " << watch_a.expired()
              << " " << watch_b.expired() << "\n";
}

struct FixedRequest {
    int id = 0;
    std::shared_ptr<FixedRequest> next;
    std::weak_ptr<FixedRequest> back; // 填完整智能指针类型：只观察前一个请求。

    ~FixedRequest() {
        std::cout << "销毁请求 " << id << "\n";
    }
};

void fixed_demo() {
    std::weak_ptr<FixedRequest> watch_a;
    std::weak_ptr<FixedRequest> watch_b;

    {
        auto a = std::make_shared<FixedRequest>();
        auto b = std::make_shared<FixedRequest>();
        a->id = 1;
        b->id = 2;

        a->next = b;
        b->back = a;
        watch_a = a;
        watch_b = b;

        std::cout << "块内计数 " << a.use_count()
                  << " " << b.use_count() << "\n";

        if (auto previous = b->back.lock()) {
            std::cout << "回看请求 " << previous->id << "\n";
        }
    }

    std::cout << "块外过期 " << watch_a.expired()
              << " " << watch_b.expired() << "\n";
}

int main() {
    fixed_demo();
}
