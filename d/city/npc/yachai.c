// Room: /d/city/npc/yachai.c �ٸ��ò�
// Last Modified by Winder on Nov. 15 2000

inherit NPC;

void create()
{
	set_name("�ò�", ({ "ya chai", "chai" }));
	set("gender", "����");
	set("age", 25);
	set("long","һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
	set("combat_exp", 7500);
	set("shen_type", 1);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set("inquiry", ([
		"����" : "�ǻ����򵥣���ֻҪ�е��������������(jie wenshu)��Ȼ���Ŀ��ɱ�˾Ϳ��ԡ�",
	]) );
	set("chat_chance", 20);
	set("chat_msg", ({
		"�ò�С���ֹ�������������˵����֮�в����Ի���Ҳ��֪�������Ǽ٣�\n",
		"�ò�����˵��������·Ӣ�ۣ�����Ŀǰ����׽�ý�����������λ��Э���ٸ���������ͽ��\n",
	}) );
	setup();
	carry_object(__DIR__"obj/yayifu")->wear();
}
