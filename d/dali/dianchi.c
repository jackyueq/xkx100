//Room: /d/dali/dianchi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG
������ܵ�ɽ����������ɽϵ������ɽ���Ķ�֧�������£��ܳ�����ɽ��
�д�С��ʮ��ɽ�塣���������ɽ���£�ɽ��ˮ���������Ӱ��������Ȼ��
ͼ������صġ��ᡱ�������м��Ǵ���ӣ���˾��Ǩ�ġ�ʷ�ǡ��������д���
���أ��ڹŴ�������һ���������Ĳ������ƣ�������ء�
LONG);
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"dasenlin",
	    "south"   : __DIR__"yanchi1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -35000);
	set("coor/y", -70300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}