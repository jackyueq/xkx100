// Room: /d/jiaxing/mishi.c
// Last Modified by winder on Nov. 17 2000

#define PAINTINGS	20

inherit ROOM;

int do_move(string);
int do_open(string);
int do_browse(string arg);
string look_jiaceng();
string look_hole();

int *index = ({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
string *paintings = ({
"��Ȼ���ǻ�ʥ����ӵġ���������ͼ����",
"û�뵽ȴ���ƴ��������ġ�����ͼ����",
"����˵ġ������Ϻ�ͼ�����㾪���ˡ�",
"ȴԭ�����ƴ���˼ѵ�ġ�����¥��ͼ����",
"��Ȼ����ά�ġ������ھ�ͼ������ά��ʫ���ƣ���ɽˮ��ȴҲ��������������ﻭ��",
"�������š�������ҹ��ͼ��������������ƻ��ҹ����е��漣��",
"���Ǳ������ġ�����ͼ����",
"�������������ġ�̫������ͼ����",
"����һ������®ͼ�������϶����С������漣��Ʒ�����֡�",
"��Ȼ�������ͬ�ġ�ɽϪ����ͼ����",
"ȴԭ��������������ġ�С����ͼ����",
"û�뵽ȴ�����ƶ�Դ�ġ�����ͼ����",
"�������š���ɽ�ʵ�ͼ����ѽ���ⲻ���γ���ɮ��Ȼ�Ĵ�����",
"���������ʵġ���ɽ����ͼ�����㾪���ˡ�",
"ԭ����������Զ�ġ���������ͼ����",
"��Ȼ���ǹ���֮�ġ�����ˮ��ͼ����",
"�����ƴ����ɵġ���ҹ�ס���",
"ԭ���Ǳ��δް׵ġ���ȸͼ����",
"ȴ����ĩ�����ġ�����ҩ��ͼ����",
"�����λ����ױ������ġ�ѩ������ͼ����",
"��ô���ܣ���Ȼ�Ǿ�˵ʧ���Ѿõı��η�����漣��Ϫɽ����ͼ����",
});

void create()
{
	int temp, i, j;

	set("short", "����");
	set("long", @LONG
����һ����ƾ��ɵ����ң������ܴ󣬵���ȴ�����˾���ӵ������
����һ�߸ɿݵĺ��� (haigu)���Ա�����һ�������˵Ĵ�����(xiang)��
ǽ����һ��СС��Բ��(kong)��ͨ�����ܿ�������������
LONG
	);
	set("no_clean_up", 0);

	set("item_desc", ([
		"haigu" : "һ�߸ɿݵĺ��ǡ�\n",
		"xiang" : "һ�ڳ��صĴ����䣬�⼣�߰ߣ����ҵ�����ǻ����Դ򿪡�\n",
		"jiaceng" : (: look_jiaceng :),
		"hole" : (: look_hole :),
		"kong" : (: look_hole :),
	]) );

	set("exits", ([
		"out": __DIR__"xiaodian",
	]) );

	set("coor/x", 1560);
	set("coor/y", -1061);
	set("coor/z", 0);
	setup();
	for (i = 0; i < PAINTINGS; i++)
	{
		j = random(PAINTINGS);
		while (j == i)
			j = random(PAINTINGS);
		temp = index[i];
		index[i] = index[j];
		index[j] = temp;
	}		
}

void init()
{
	add_action("do_move", ({"move", "yi"}));
	add_action("do_open", ({"open", "kai", "dakai"}));
	add_action("do_browse", ({"browse", "check", "examine", "fan", "cha", "liulan", "jiancha"}));
}

string look_jiaceng()
{
	if (this_player()->query_temp("thd_jiaceng")) 
		return "����һ�����ɵ���ƣ����򿪼в����ǿ���������Ķ����ġ�\n";
	return "��Ҫ��ʲô��\n";
}

string look_hole()
{
	"/cmds/std/look.c"->main(this_player(),"out");
	return "";
}

void delete_tiepai()
{
	delete("tiepai_got");
}

void delete_shanshui()
{
	delete("shanshui_got");
}

void delete_xishan()
{
	delete("xishan_got");
}

int do_move(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (arg == "haigu") {
		if (!query("tiepai_got") && !present("qulingfeng tiepai", me)
		&& !present("qulingfeng tiepai",this_object())) {
			write("������Ų��ʬ�壬����ԭ����ʬ�����滹ѹ��һö���ơ�\n");
			set("tiepai_got",1);
			new(__DIR__"obj/tiepai")->move(this_object());
			remove_call_out("delete_tiepai");
			call_out("delete_tiepai", 300);
		}
		else {
			write("������Ų��ʬ�壬ȴʲôҲû�з��֡�\n");
		}
		return 1;
	}
	return notify_fail("��Ҫ�ᶯʲô��\n");
}

int do_open(string arg)
{
	int thdx, thdy;
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (arg == "xiang") {
		if (me->query_temp("thd_jiaceng")) {
			write("�����Ѿ�������ˣ�\n");
			return 1;
		}
		thdx = random(20) + 30;
		thdy = random(20) + 30;
		write("���þ��������ӣ��������澹�����������Ĵ����ܱ���
�����鱦�����棬��һ�ŷ��Ƶĺ�ͼ��\n");
		write("�м��һ���ط��ôֱʻ��˸�ԲȦ���Ա����ʲݵ��ּ�д��(" + thdx + "," + thdy + ")��������\n");
		write("����ϸ�ع۲�������ӣ��ƺ������мв�(jiaceng)��\n");
		me->set("thd/x",thdx);
		me->set("thd/y",thdy);
		me->set_temp("thd_jiaceng", 1);
		return 1;
	}
	if (arg == "jiaceng") {
		if (me->query_temp("thd_jiaceng") == 1) {
			me->set_temp("thd_jiaceng", 2);
			me->set_temp("thd_shanshui", 10 + random(5));
			me->delete_temp("thd_painting");
			write("������ط����в㣬�������澹Ȼ��һ����Ļ���(painting)��\n�������������ľ�Ʒ��\n");
			return 1;
		}
		else if (me->query_temp("thd_jiaceng")) {
			write("�в��Ѿ�������ˣ�\n");
			return 1;
		}
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_browse(string arg)
{
	object me = this_player();
	int painting_no;

	if (me->query_temp("thd_jiaceng") < 2)
		return 0;

	if (arg != "hua" && arg != "painting")
		return notify_fail("��Ҫ����ʲô��\n");

	painting_no = me->query_temp("thd_painting");
	me->add_temp("thd_painting", 1);
	if (painting_no == me->query_temp("thd_shanshui") && !query("shanshui_got") && me->query_temp("find_shanshui") && !present("shanshui hua", me) && !present("shanshui hua", this_object()))
	{
		write( "�����ִ�һ�ử����һ����īɽˮ��������ú���ֵ��ǣ��˻������ѣ������˺������£������������ֱʡ�\n");
		new(__DIR__"obj/shanshui")->move(this_object());
		set("shanshui_got",1);
		remove_call_out("delete_shanshui");
		call_out("delete_shanshui", 300);
		return 1;
	}
	if (painting_no > PAINTINGS)
		return notify_fail("�㶼�����ˣ���������������\n");
	write("�����ִ�һ�ử��" + paintings[index[painting_no]] + "\n");
	if (painting_no == PAINTINGS && !query("xishan_got") && !present("xi shan xing lv tu", me)
	&& !present("xi shan xing lv tu", this_object())) {
		new(__DIR__"obj/xishanxinglvtu.c")->move(me);
		set("xishan_got",1);
		remove_call_out("delete_xishan");
		call_out("delete_xishan", 500);
		return 1;
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("thd_jiaceng");
	me->delete_temp("thd_shanshui");
	me->delete_temp("thd_painting");
	return ::valid_leave(me, dir);
}