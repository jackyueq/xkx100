// yayi.c  �ٸ�����

inherit NPC;

void create()
{
	set_name("����", ({ "ya yi", "ya" }));
	set("gender", "����");
	set("age", 25);
	set("long","һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
	set("combat_exp", 7500);
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set("inquiry", ([
		"����" : "�ǻ����򵥣���ֻҪ�е��������������(jie wenshu)��Ȼ���Ŀ��ɱ�˾Ϳ��ԡ�",
	]) );
	set("chat_chance", 20);
	set("chat_msg", ({
		"����С���ֹ�������������˵����֮�в����Ի���Ҳ��֪�������Ǽ٣���\n",
		"��������˵��������·Ӣ�ۣ�����Ŀǰ����׽�ý�����������λ��Э���ٸ���������ͽ����\n",
	}) );
	setup();
	carry_object("/d/city/npc/obj/yayifu")->wear();
}
