// Last Modified by winder on Sep. 12 2001
// shi-shuangying.c ʯ˫Ӣ

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("ʯ˫Ӣ", ({ "shi shuangying", "shi","shuangying" }));
	set("title", HIR "�컨��"HIG"ʮ������" NOR);
	set("nickname", HIG "�����" NOR);
	set("long", 
"�����ʯ˫Ӣ�ڻ�������ʮ���ѽ��Σ�ִ�����ã�������˽���ĺ���
�������˹����ľ����ӵ����ĺ��ǣ���Ҳ������ץ�����̣�ԭ�����ݺ�
��������������ֵܷ��˴������һʱ��Ϳ���˺���Ļ��򣬿��ڿ�
����ִ��֮ǰ�������ü⵶�ڴ�����������������������Դ���������
��ν��������������Ȼ����ùܶ�����ִ��������ˡ���������ᷢ�䣬
�����������س��Բ�����ˡ�����Ժ컨�������ֵܣ��ᵽ�����ʱ�޲�
�Ȼ��\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1500);
	set("max_jing", 700);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 200000);

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("hand", 90);
	set_skill("parry", 90);
	set_skill("sword", 90);
	set_skill("benlei-shou", 125);
	set_skill("honghua-shengong", 90);
	set_skill("zhuihun-jian", 120);
	set_skill("youlong-shenfa", 120);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("hand", "benlei-shou");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.zhuihun" :),				
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�컨��", 2, "����");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}


