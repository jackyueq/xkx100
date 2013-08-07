// hong.c �鰲ͨ

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("�鰲ͨ", ({ "hong-antong", "hong" }));
        set("nickname", HIR "�����ɸ�" NOR);
	set("long", "�������书����������˵�̸֮ɫ��������̽����鰲ͨ��\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 400000);

	set_skill("force", 200);
 	set_skill("dulong-dafa", 200);
	set_skill("dodge", 200);
	set_skill("yixingbu", 300);
	set_skill("hand", 200);
	set_skill("shenlong-bashi", 300);
	set_skill("strike", 200);
	set_skill("huagu-mianzhang", 300);
	set_skill("finger", 200);
	set_skill("yingxiong-sanzhao", 300);
	set_skill("meiren-sanzhao", 300);
	set_skill("hook", 200);
	set_skill("ruyi-hook", 300);
	set_skill("staff", 200);
	set_skill("shenlong-staff", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("literate", 90);
	set_skill("digging", 200);
	set_skill("leg", 200);
	set_skill("jueming-leg", 300);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("leg", "jueming-leg");
	map_skill("finger", "yingxiong-sanzhao");
	map_skill("hand", "shenlong-bashi");
	map_skill("hook", "ruyi-hook");
	map_skill("staff", "shenlong-staff");
	map_skill("parry", "yingxiong-sanzhao");
	prepare_skill("finger", "yingxiong-sanzhao");
	prepare_skill("hand", "shenlong-bashi");
	set("party/party_name", HIY"������"NOR);
	set("party/rank", HIM"����"NOR);
	set("party/level", 3);
	create_family("������",1,"����");

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("silver", 50);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say ������˵��������������Ƹ������⡣");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="su-quan")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        command("say �ὣ��ָ����֮�ơ�����");
        return;
}

