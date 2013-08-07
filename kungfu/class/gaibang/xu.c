// xu.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�쳤��", ({"xu zhanglao", "xu", "zhanglao"}));
	set("gender", "����");
	set("age", 85);
	set("long", "����Ʈ��������һ�������۵����£��Ǹ���ͼ��ߵ���ؤ��\n");

	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);

	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 95);            // �����ڹ�
	set_skill("huntian-qigong", 90);   // ��������
	set_skill("hand", 90);             // �����ַ�
	set_skill("suohou-hand", 85);      // ����������
	set_skill("staff", 90);            // �����ȷ�
	set_skill("fengmo-staff", 85);     // ��ħ�ȷ�
	set_skill("dodge", 90);            // ��������
	set_skill("xiaoyaoyou", 95);       // ��ң��
	set_skill("parry", 85);            // �����м�
	set_skill("staff", 90);            // ��������
	set_skill("strike",85);  // �����Ʒ�
	set_skill("lianhua-zhang",85); // ������
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 8, "����");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

#include "/kungfu/class/gaibang/gaibang.h"
