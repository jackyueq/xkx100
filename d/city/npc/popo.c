// popo.c
// Last Modified by Winder on Jul. 15 2000

inherit NPC;
void create()
{
        set_name("������", ({ "lao popo","old","popo" }) );
        set("title", "ƽ��" );
        set("gender", "Ů��" );
        set("age", 65);
        set("combat_exp",100);
        set("long","�������ſ�������ü��Ŀ���ر���ס�\n");
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin",100);
}
