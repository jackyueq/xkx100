// huahegen.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "hua hegen", "hua" }));
	set("title",  "����˾ͽ" );
	set("long", "���Ǵ��������֮һ��
��˾ͽ��������������ƶ�����ֽ��ڴ����λ��������δ����ʱ����
����ȴ�ǵ�Ĺ��صĹ�����  ���ó��ı�����͵�������޼ֵķ�Ĺ����Щ��������
���󣬱������챦��ѳ�ᣬ�������Ӽ�Զ���ھ�ص���ͨ���Ĺ��Ȼ���ȡ���
������һ����ޣ�ȴ�ɴ˶���δΪ�˷�������һ��������һ�أ��ڹ�ľ�еõ���һ
��ѳ����书�ؾ���������ϰ��������һ��׿�������Ź��򣬱����������¼���Ӫ
�������������ۣ������湦����������˾ͽְ֮��\n");
	set("gender", "����");
	set("age", 40);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 25);
	set("env/wimpy", 60);	
	
	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 750000);
	set("score", 200000);

        set_skill("force", 80);
        set_skill("dodge", 90);
        set_skill("parry", 80);
        set_skill("cuff", 95);
        set_skill("sword", 80);
        set_skill("staff", 80);
	set_skill("kurong-changong", 80);
        set_skill("tiannan-step", 135);
        set_skill("jinyu-quan", 145);
        set_skill("duanjia-sword", 120);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("parry", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),				
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver", 20);

	create_family("����μ�",19,"�佫");
}

int accept_object(object who, object ob)
{
	object tool;
	if (ob->id("axiang letter")) 
	{
		tell_object(who, "���������һ�Ⱒ����š�\n");
		tell_object(who, "�����޲��ſ��˿�����ͷ˵��������Ȼ�ǰ���д�������ҾͰѶ�������ɡ���\n");
		destruct(ob);
		tool = new("/d/suzhou/npc/obj/diggertools");
		tool->move(who);
		tell_object(who, "�����޸���һ�׵�Ĺ���ߡ�\n");
		return notify_fail("���������˰�����š�");
	}
	return 0;
}

