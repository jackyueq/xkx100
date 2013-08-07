// Room: /d/taohua/hill2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

string look_bei();
int do_study(string arg);

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ɽ����������أ��㷢�ֶ�����һ����̨��һ��ʯ����ն�
�ܣ�������������Ǳߵ���ڡ�����֮������һ��ʯ��(shibei)��
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"hill1",
		"east" : __DIR__"entrance",
	]) );
	set("item_desc", ([
		"shibei" : (: look_bei :),
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");
	set("coor/x", 8510);
	set("coor/y", -4680);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_study", "du");
	add_action("do_study", "study");
}

string look_bei()
{
	write("ʯ���Ͽ��ţ�\n");
	write("    һ��֮���󣺵���֮ʱ����ҫ���գ���ԡɽ�ӣ�����֮��ʢ����Ϊ̫����\n");
	write("                ����֮ʱ���ս���ɽ��Ⱥ�����֣���˥����ʢ����Ϊ������\n");
	write("                ����֮ʱ�����ö�������������������֮��ʢ����Ϊ̫����\n");
	write("                ��î֮ʱ�����ճ��֣�Ⱥ���޹⣬��ʢ����˥����Ϊ������\n");
	write("    һ��֮�������Գ�һ����ʮ�壬������Բ������֮����Բ��������ʢ��\n");
	write("                ʮ��֮��������ȱ������֮����ȱ��������˥��\n");
	write("    һ��֮��֧��������������ȥ��Ȫ�����飬����ǿҲ������������\n");
	write("                ��������ð�ض���������֮�Ρ�ð����î��\n");
	write("                �������������׵�����ũʱҲ��������������ڳ���\n");
	write("                ���������ѳ���������ï��������������¡���ʢ���ȡ�\n");
	write("                ����������������ð�����Ҳ���䲼���硣\n");
	write("                ������ζҲ����ľ��֦ҶҲ��ζů��δ��\n");
	write("                �����������壬���궫��������ꡣ\n");
	write("                ������ɿ������ơ���ִ���ϡ�\n");
	write("                ��������΢������ϳɣ��������Ҳ�������硣\n");
	write("                ʮ��΢����������ú��ں���\n");
	write("                ʮһ���������������̡��������ӡ�\n");
	write("                ʮ�������ﶯ���£��������Ρ�Ŧ���ڳ�\n");
	write("    ����֮���ϣ�ˮ��������������������֧��ˮ��\n");
	write("                ����������������������֧�Ի�\n");
	write("                ľ������î����δ������֧��ľ��\n");
	write("                ����������������������֧�Խ�\n");
	write("                ����������������������֧������\n");
	return "";
}

int do_study(string arg)
{
        object me = this_player();

	if (arg != "shibei" && arg != "bei")
		return 0;

	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}

	if( me->is_fighting() ) {
		write("���޷���ս����ר�������о����ϵ����֣�\n");
		return 1;
	}

	if (me->query("jing") < 30) {
		write("��̫���ˣ��޷����о������о����ϵ����֡�\n");
		return 1;
	}
	if (me->query_skill("qimen-wuxing", 1) > 150) {
		write("����ϸ�ض���һ�鱮�ϵ����֣������Ѿ�̫ǳ���ˣ��޷�ѧ���µ�֪ʶ��\n");
		return 1;
	}
	if (me->query_skill("qimen-wuxing", 1) < 50) {
		write("����ϸ�ض���һ�鱮�ϵ����֣��е��޷���ȫ��⡣\n");
		return 1;
	}
	me->receive_damage("jing", 25);
	message_vision("$N��ϸ��ע����ʯ���ϵ����֡�\n", me);
	write("�������������֮ѧ�ľ���֮�����˽�һ������ʶ��\n");
	me->improve_skill("qimen-wuxing", me->query("int") / 2 + random(me->query("int") / 2));
	return 1;
}