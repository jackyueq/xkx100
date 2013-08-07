// Room: /d/gaibang/undertre.c
// Date: Haa 96/03/22

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ϻ����ײ������ܹ��߻谵����Ӱ�λΣ��ƺ��м����ڰ��Ķ�
��������ߣ�ͨ������˷���һλ����ؤ�����ֵ��������еĵ��ϡ���
�������㷢��ǽ���ϻ��ŷ��ֲڵ�·�߲�ͼ��map����
LONG );
	set("no_fight", 1);
	set("exits", ([
		"up"   : __DIR__"inhole",
		"west" : __DIR__"chuchang",
		"0"    : __DIR__"yyandao1",
		"1"    : __DIR__"xcandao1",
		"2"    : __DIR__"zlandao1",
		"3"    : __DIR__"slandao1",
		"4"    : __DIR__"xxandao1",
		"5"    : __DIR__"wdandao1",
		"6"    : __DIR__"hsandao1",
		"7"    : __DIR__"bjandao1",
		"8"    : __DIR__"qzandao1",
		"9"    : __DIR__"xsandao1",
		"a"    : __DIR__"dlandao1",
		"b"    : __DIR__"fzandao1",
		"c"    : __DIR__"wxandao1",
		"f"    : __DIR__"cdandao1",
	]));
	set("item_desc",([ "map" : 
		"�����㣺ͨ��������\n"
		"����һ��ͨ��С�塣\n" +
		"���ڶ���ͨ�����֡�\n" +
		"��������ͨ�����֡�\n" +
		"�����ģ�ͨ�����ޡ�\n" +
		"�����壺ͨ���䵱��\n" +
		"������: ͨ����ɽ��\n" +
		"�����ߣ�ͨ��������\n" +
		"���ڰˣ�ͨ�����ˡ�\n" +
		"���ھţ�ͨ��ѩɽ��\n" +
		"���ڣ���ͨ������\n" +
		"���ڣ£�ͨ�����ݡ�\n"
		"���ڣã�ͨ��������\n"
		"���ڣƣ�ͨ���ɶ���\n"
	]));
	set("objects",([
		CLASS_D("gaibang") + "/liang" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", -20);
	setup();
}

void init()
{
	object ob = this_player();
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if (!myfam || myfam["family_name"] != "ؤ��")
	{
		message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
		ob->move("/d/gaibang/inhole");
		message("vision", "ֻ����ƹ����һ����" + ob->query("name") + "��С������˳�����\n", environment(ob), ob);
	}
}
