// Room: /d/mingjiao/xuantianshi.c


inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
��ʯ��Զ����ֻ���ƺ���ã�����վ�������������һ��������ǧ�
��һ�ɴ�ý�ɽ����������ʯ��������ഫ˵���ഫ���̵���ʮ������
��������Ӱ������(Doll)Ϊ������֮�ѣ������ڴˣ�����һ����ѧ��Ǭ
����Ų�ơ��Ӵ�ʧ����������֮���ڴ�ƾ����Ī�����ᣬ���������
�Ӵ�ʯ���£���Ѱ�ҡ�Ǭ����Ų�ơ��ؼ���ȴ��û�����ܰ�Ȼ���顣
LONG );
	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));
	set("item_desc", ([
		"doll" : "һ�����Բ�˹�̵ܽĽ�����\n",
	]));
	set("outdoors", "mingjiao");
	set("coor/x", -52030);
	set("coor/y", 810);
	set("coor/z", 40);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
