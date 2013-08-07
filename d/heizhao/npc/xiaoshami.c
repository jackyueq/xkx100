// xiaoshami.c
inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("Сɳ��", ({"xiao shami","shami",}));
	set("long",
	"���Ǳ���Сɳ�֡�\n");
	set("gender", "����");
	set("age", 12);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);

	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	setup();

	carry_object("/d/shaolin/npc/obj/dao-cloth.c")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if( (myfam["master_id"] == "yideng dashi") &&
		! environment(this_object())->query("exits/out"))
	{
message_vision(HIY"Сɳ�ֶ�$N˵����������ˡ�ȥ��ʦ���ɡ���˵�Ŵ򿪺��š�\n"NOR, ob);
		environment(this_object())->set("exits/out","/d/heizhao/zhulin1");
	}
	return;
}

int accept_object(object who, object ob)
{
	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");

	if ( (string)ob->query("id") != "huangbu xiaonan")
		return notify_fail("Сɳ�ֲ���Ҫ���������\n");
	environment(this_object())->set("exits/out","/d/heizhao/zhulin1");
message_vision(HIY"Сɳ�ֵ��˵�ͷ������Ժ���Ŵ�����\n"NOR, who);
	return 1;
}

