// fangjian1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Կ���������ǰ������һ������ĵط����������һ��ʯ������
ֻ����֮�⣬�յ�����һ�����У�ʯ���Ͽ����ݺ�ʮ�ŵ���·�������
���Ŷ��ٶ�����ӣ�ȴ�Ǻڰ׶��ţ���Ȼ��һ��û��������塣
LONG );
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50030);
	set("coor/y", -21030);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}