#include <ansi.h>
inherit NPC;

int do_walk();

void create()
{
	set_name("·��", ({ "lu ren", "man", "ren" }) );
        set("gender", "����");
        set("age", 53 + random(20));
        set("long","����һ��ʰ���ߣ�����ȥ��ʵ�ͽ��ġ�������˵���͹ٸ��н��飬��ñ�ȥ���ǡ�\n");
        set("attitude", "heroism");
        set("str", 35);
        set("int", 15);
        set("con", 19);
        set("dex", 17);

        setup();
        carry_object(CLOTH_DIR"cloth")->wear();
}
