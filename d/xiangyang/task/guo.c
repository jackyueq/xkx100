// Last Modified by Sir 2003.11.12
// guojing.c ����

inherit NPC;
#include <ansi.h>
inherit __DIR__"gysjob.c";  //��ʿ����
inherit __DIR__"teamjob.c"; //��ؼ�ϸ����
inherit __DIR__"scjob.c"; //�س�����

void create()
{
	set_name("����", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"����"NOR);
	set("gender", "����");
	set("age", 41);
	set("long", 
		"�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������\n"
		"�����߹֡�ȫ�������ڡ�����ؤ�����߹��͡�����ͯ���ܲ�ͨ\n"
		"���˵�ͽ�ܣ���������书��������һ����ɫ���ۣ���̬���࣬\n"
		"�غ����Ŀ��͸��һ�����ϡ����˲��ɵò���һ������֮�顣\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 20);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set_temp("no_kill",1);
	set("no_get",1);
	set("chat_chance", 3);
	set("chat_msg", ({
		"����̾�˿������� �ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ�����ߣ���....\n",
		"����˵�������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
//		(: random_move :),
	}));
	set("inquiry", ([
		"�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�\n",
		"����ͯ" : "�ܴ��һ��������û��������\n",
		"���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�\n",
		"��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�\n",
		"һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���\n",
		"ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�\n",
		"����"   : "�ض����ҵİ��ޣ�������������\n",
		"�ض�"   : "�ض������ض��ˡ�������ô����\n",
		"��ܽ"   : "���Ů�����ֱ��ֲ�������\n",
		"����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����\n",
		"����²" : "�����ҵ�С���ӡ�\n",
		"���"   : "����ȷʵ�г�Ϣ��\n",
		"����"   : "����������а�ʦ֮�ꡣ\n",
		"�𴦻�" : "������屡���죬������ܡ�\n",
		"�����" : "�����Ҵ�ʦ����\n",
		"���"   : "�����Ҷ�ʦ����\n",
		"������" : "��������ʦ����\n",
		"��ϣ��" : "��������ʦ����\n",
		"�Ű���" : "��������ʦ����\n",
		"ȫ��" : "��������ʦ����\n",
		"��СӨ" : "��������ʦ����\n",
		"ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
		"��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
		"job"    : (: ask_job :),
		"��ʿ"   : (: ask_job :),
		"��ϸ"   : (: ask_jianxi :),
		"�س�"   : (: ask_shoucheng :),
		"job2"   : (: ask_shoucheng :),
	]));
	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	set("combat_exp", 25000000);
	set("score", 200000);
	set_skill("force", 400);		// �����ڹ�
	set_skill("huntian-qigong", 400);	// ��������
	set_skill("unarmed", 400);		// ����ȭ��
	set_skill("xianglong-zhang", 400);	// ����ʮ����
	set_skill("dodge", 400);		// ��������
	set_skill("xiaoyaoyou", 400);		// ��ң��
	set_skill("parry", 400);		// �����м�
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("job_over","shoucheng");
}
