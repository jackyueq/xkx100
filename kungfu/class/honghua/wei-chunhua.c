// Last Modified by winder on Sep. 12 2001
// wei-chunhua.c ������

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("������", ({ "wei chunhua", "wei","chunhua" }));
	set("title", HIR "�컨��"HIG"�ŵ���" NOR);
	set("nickname", HIY "����������" NOR);
	set("long", 
"��������ĿӢ������һ���಼��������ʮ��������ͣ�˫Ŀ������
Ӣ�����ˡ����꽭������Ź�������Կ��ٱ�֮ʱ�����������ǲ���
����������ֱǰ��һ���������ղ�����������������Ҳδ�ܹ�һ�Σ�
����˵���о���������\n");
	set("gender", "����");
	set("class", "swordsman");
	set("age", 31);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 250000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("baihua-cuoquan", 150);
	set_skill("honghua-shengong", 100);
	set_skill("zhuihun-jian", 150);
	set_skill("youlong-shenfa", 150);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("cuff", "baihua-cuoquan");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.zhuihun" :),	
		(: perform_action, "cuff.cuo" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�컨��", 2, "����");

 	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

