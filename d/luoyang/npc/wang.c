// wang.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("��Ԫ��", ({ "wang yuanba", "wang", "yuanba" }) );
	set("title", HIY"����"NOR"����������");
	set("nickname", HIG"���ݴ���"HIY"���޵�"NOR);
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 70);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
"��Ԫ��������ʮ���꣬�����⣬���һ�Գ����İ���Ʈ����ǰ������
���壬����Ǻ�ॵ�������ö�쵰��С�Ľ𵨡���������������������
��Ѱ���������������򴿸���������Ԫ���������յ�ȴ����ö�Ƴγε�
�𵨣���֮����������һ�����࣬���Ҵ��Ի���֮����\n" );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("throwing", 100);
	set_skill("feixing-shu", 100);
	set_skill("yanfly", 100);
	set_skill("parry", 100);
	map_skill("throwing", "feixing-shu");
	map_skill("parry", "feixing-shu");
	map_skill("dodge", "yanfly");

	setup();
	carry_object(__DIR__"obj/jindan")->wield();
	carry_object(CLOTH_DIR"jinduan")->wear();
	add_money("gold", 5);
}

