// Room: /heizhao/xiaowu.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
��첽�߽��ٲ���ֻ������������ͷ�����ң��������£�����
һ��ʯ�ϣ����Դ��������ٲ�ˮ���ļ��쳣��һк��ע��ˮ������
���㣿��Ȼ���㣬��������Ͼ�̶���������ʱ������˫Ŀһ������
������ˮ�С�
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"pubu",
		"north" : __DIR__"pububian",
	]));
	set("coor/x", -5020);
	set("coor/y", -1270);
	set("coor/z", 20);
	setup();
}

void init()
{
	object ob = this_player();
	if (!ob->query_temp("yu_allow"))
	{
message_vision("\n�����������$N������ȥ������һ�죬��$N���˳�����\n\n", ob);
		message("vision","ֻ����ѽ����һ����" + ob->query("name") +
		"��С������˳�����ˤ�ڵ��ϡ�\n", environment(ob), ob);
		ob->move(__DIR__"pubu");
		return;
	}
}