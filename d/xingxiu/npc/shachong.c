// npc: /d/xingxiu/npc/shachong.c

inherit NPC;

void create()
{
        set_name("ɳ��", ({ "sha chong", "chong", "bug" }) );
	set("race", "����");
	set("subrace", "����");
        set("age", 3);
        set("long", "һֻ�ƺ�ɫ��С�׳棬β�����л������Ļ��ơ����ֱ������\n"
"����һ���ж���\n");
        set("attitude", "peaceful");
        set("combat_exp", 300);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 2);
        set_temp("apply/armor", 1);

        setup();
}

void die()
{
        object ob;
        message_vision("$Nð��һ����ˮ�����ˡ�\n", this_object());
        ob = new(__DIR__"shachongke");
        ob->move(environment(this_object()));
        destruct(this_object());
}

