inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("�����", ({ "liu dahong", "liu" }));
	set("nickname", HIY"��������"NOR);
	set("title", "�������ҽ�");
	set("long","һ��ͷ���԰׵����ߣ�������ɫ����Ŀ��ࡣ\n�����ǽ������˳���������������飬Ҳ����\n�����������彣����ʦ����\n");
	set("gender", "����");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);	
	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 20000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("hunyuan-yiqi", 150);
	set_skill("qianye-shou", 150);
	set_skill("shaolin-shenfa",150);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "qianye-shou");
	map_skill("strike", "qianye-shou");

	prepare_skill("strike", "qianye-shou");

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}
