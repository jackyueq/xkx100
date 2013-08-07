// Last Modified by winder on Sep. 12 2001
// zhang.c �½�

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("�½�", ({ "zhang jin", "zhang","jin" }));
	set("title", HIR"�컨��"HIG"ʮ����"NOR);
	set("nickname", HIM"ʯ�ҵ�"NOR);
	set("long", 
"���Ǹ����ӣ�����ֱ���ӡ��������м��������������ˣ���
����һ����ҵ�Ӳ����������ȱ�ݣ����ձ���ȡЦ������
����������˵��ʱ�Գơ������ӡ������Ǻö˶˵أ�Ȼ����
������������ǰ�ᵽ�����ա��֣��������������ձ�һЦ��
�������������˻�����Ц��֮�����ǳ���Ҳ�����ˣ������
�գ������ͱ������ʵʵ�Ĵ���һ�١����ں컨����������
���Ļ�������Ƣ���Ź֣����˶��������֣����ȴ�����зϣ�
������ʳ��ʱ��ϸ�����ϣ�������С�ֵ�һ�㡣�·���Ϊ��
�ʡ���òȴ��Ϊ��ª��\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1200);
	set("max_jing", 700);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 120000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("cuff", 70);
	set_skill("honghua-shengong", 70);
	set_skill("youlong-shenfa", 150);
	set_skill("baihua-cuoquan", 150);
	set_skill("benlei-shou", 150);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("hand", "benlei-shou");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("parry", "baihua-cuoquan");
	prepare_skill("hand", "benlei-shou");
	prepare_skill("cuff", "baihua-cuoquan");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("�컨��", 2, "����");

 	setup();
	carry_object(WEAPON_DIR"gangzhang");
	carry_object(CLOTH_DIR"jinpao")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();
}


