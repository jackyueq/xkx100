// Room: /d/baituo/fendi.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�����ǻ�����ɭ�Ļķصء�һ���ذ�����һ���ذ����еķذ��ϻ�
����һ֧��ͣ�����һ���������еķذ�����ʲô��û�С���ֻ��ѻվ
�ڷص���Ŀ�֦�ϣ���ʱ�����������
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
		"north"     : __DIR__"mumen",
	]));
	set("objects" , ([
		__DIR__"npc/guafu" : 1,
	]) );
	set("coor/x", -49960);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
