//Room: /d/dali/feilihueast.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��������");
	set("long",@LONG
��վ���������Ķ��������µ���·�ƺ��������ϱ��Ĵ�������
����ֻ�����۵�㣬���ǲ����̨���񷤡�·�߾����������֣�̨��
����¥�����֡�������ȥ�Ĳ�·ͨ�����������Բ�����·����ֱ��
���ڳǡ�
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"longkou",
	    "northwest"  : __DIR__"feilihu",
	    "southwest"  : __DIR__"hexi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -39000);
	set("coor/y", -89100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}