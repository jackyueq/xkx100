// Room: /d/taishan/sandengya.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ؽ׶��ϣ����������£����о�ʯ���ݣ���������䣬ʢ��������
�꣬ʯ��ɽ��׹�ˣ����ܸ��⡰����ʯ��������ƺ��������ʯ��������
������
LONG );
	set("exits", ([
		"eastdown"   : __DIR__"yunbu",
		"westup"     : __DIR__"wudafu",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 380);
	set("coor/y", 680);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
