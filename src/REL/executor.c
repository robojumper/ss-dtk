extern void ModuleProlog();
extern void ModuleEpilog();
extern void ModuleUnresolved();
extern void ModuleConstructorsX(void* const*);
extern void ModuleDestructorsX(void* const*);

extern void* const _ctors[];
extern void* const _dtors[];

extern void _prolog() {
    ModuleConstructorsX(_ctors);
    ModuleProlog();
}

extern void _epilog() {
    ModuleEpilog();
    ModuleDestructorsX(_dtors);
}

extern void _unresolved() {
    ModuleUnresolved();
}
