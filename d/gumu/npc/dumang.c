// Room: /d/gumu/npc/dumang.c
// Last Modifyed by Winder on Jan. 14 2002

inherit NPC;

void create()
{
        set_name("����", ({ "du mang", "mang" }));
	set("race", "����");
        set("age", 200);
        set("long", "һ���Ӵ��ޱ�, ɫ�ʰ�쵵ľ����� ����������ǿ�ҵ��ȳ�ζ��\n");
        set("attitude", "aggressive");
        set("str", 70);
        set("con", 50);
        set("max_qi", 800);
        set("combat_exp", 200000);
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 50);
        setup();
}

