// walker.c

#include <ansi.h>
inherit NPC;

void create()
{
	mapping name;

	name = NAME_D->man_name();
	set_name(name["name"],({name["id"]}));
        set("gender", "����");
        set("age", 53 + random(20));
        set("long", @LONG
����һ��ʰ���ߣ�����ȥ��ʵ�ͽ��ġ�������
˵���͹ٸ��н��飬��ñ�ȥ���ǡ�
LONG);
        set("attitude", "heroism");
        set("str", 35);
        set("int", 15);
        set("con", 19);
        set("dex", 17);

        setup();
        carry_object(CLOTH_DIR"cloth")->wear();
}

