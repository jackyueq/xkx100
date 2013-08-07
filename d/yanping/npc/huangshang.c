// huangshan.c ����
// Last Modified by winder on Aug. 18 2002

inherit NPC;
string ask_book();
string ask_jing();

void create()
{
	set_name("����", ({ "huang shang", "huang", "shang" }));
	set("long","
�������ѣ������ˣ������١�����ɽ�������겻�ꡣ
��������Ϊ����ʱ�����п�����֮־��������״����ҽ�̶֮������ţ֮
�⣬�������գ�����֮�ţ�ʱ�б��֡�����������ƣ�����ȡ����ɳ���� 
���Ƿ�������ꡣ��Ԫ�����꣨1081������֮���ţ���Ϊ��������������
��֮����ʫ������������ҹ�ƿ�֦�������칫�����ޣ�Ī�������ټ�����
�Ž�ͷ������顣�����꣬���ѶԲߣ���Ϊ���µ�һ�������ڶԻ���֮��
�¼�Ϊϲ뼣������ʿ���л��������������Բߣ�ǰ��λ�Բ�������֮
�⣬���ڵȻ��������֣���δ�ײ�ʼ����������ߪΪ��һ�����������ʧ
ʵ��������
��������Ϊ���������ˡ����ͼ䣨1111��1118����֪���ݣ���Ϊ�����ɣ�
Ǩ���顣��ʱ���ᷨʵ�У�������Ϊ���˽�����Զ�����ٲ����ϣ��˸���
��ƶ�����������ڿƾ�֮�ơ������������ʮ���꣬���С���ɽ������ʮ
����������
    ��ʷ�ϣ�������һ��������������Ե��

");
	set("gender", "����");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_jing", 3000);
	set("max_qi", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 5000000);
	set("score", 60000);
	set("inquiry", ([
		"�ؼ�" : (: ask_jing :),
		"jing" : (: ask_jing :),
		"book" : (: ask_book :),
		"�����澭" : (: ask_jing :),
		"���ٵ���" : (: ask_book :),
	]));
	set("book_count", 1);
	set("jing_count", 1);
	setup();
}

string ask_book()
{
	mapping fam; 
	object ob, me = this_player();

	if (query("book_count") < 1)
		return "��ô���ص��飬"+RANK_D->query_respect(me)+ "Ҫ������ɶ�ã�";
	if (me->query_skill("taoism",1) < 100)
		return "�ⲿ���ٵ���̫�����"+RANK_D->query_respect(me)+ "���¶������գ�";
	add("book_count", -1);
	ob = new(BOOK_DIR"daojing");
	if (ob->violate_unique())
	{
		destruct(ob);
		return "��ô���ص��飬"+RANK_D->query_respect(me)+ "Ҫ������ɶ�ã�";
  }
	ob->move(environment(me));
	command("rumor "+me->query("name")+"�õ����ٵ�������\n");
	tell_room(environment(me), "����ת����ȥ��������ϱ���һ�����飬���ڵ��ϡ�\n", ({ob}));
	return "�ðɣ��ⲿ�����ٵ��ء����û�ȥ�ú����С�";
}

string ask_jing()
{
	mapping fam; 
	object ob, me = this_player();
	mixed sks;
	string skl;
	
	if (query("jing_count") < 1)
		return "�������澭�����Ҽ�ʮ����Ѫ��פ�����������";
	if ( !me->query("xkd/skill") )
		return "�������澭�������书�����"+RANK_D->query_respect(me)+ "���¶������գ�";
	if ( me->query("kar") != query("kar") && !wizardp(me))
		return "������Ե��ѧϰ�书Ҳ�������ģ��㿴���ܲ��ɣ���Ҫ�ġ������澭�����˽���δ����";
	add("jing_count", -1);
	ob = new(BOOK_DIR"9book");
	if (ob->violate_unique()) 
	{
		destruct(ob);
		return "�������澭�����Ҽ�ʮ����Ѫ��פ�����������";
	}
	sks = me->query("xkd/skill");
	if (arrayp(sks))
		skl = sks[random(sizeof(sks))];
	else	if (stringp(sks))
		skl = sks;
//	ob->set("skill/name", me->query("xkd/skill") );
	ob->set("skill/name", skl );
	ob->set("skill/exp_required", 1000000);
	ob->set("skill/jing_cost", 50);
	ob->set("skill/difficulty", 50);
	ob->set("skill/min_skill", 300);
	ob->set("skill/max_skill", 350);
	ob->move(me);
	command("rumor "+me->query("name")+"�õ������澭ԭ������\n");
	return "�Ȿ�������澭������ȥ�ú����У����н��档";
}
