struct func_t {
    void (*func)();
};

void foo() __attribute__ ((used));

void foo()
{
}

int toto()
{
}

struct func_t foo_t __attribute__ ((section ("foo_section") used)) =  { foo };
