from torch.utils.cpp_extension import load

# "sss"只是拿来编译的名字，可以随便起
test = load(
    "sss",
    sources=["./main.cpp"],
)


def return_on_python(ss: str) -> str:
    return "返回点儿啥吧" + ss


if __name__ == '__main__':
    print('尝试加载', test.main(), test.test())
