//Room: /d/dali/jingzhuang6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
���������������е��з��񸡵�����������������ܣ���η�����
������죬����Э���������Ⱦ����������ɣ���������������������
�����ǵ���ʯ����������Ʒ���������ļҽ��ޡ������������˼�ƷҲ
����
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "up"    : __DIR__"jingzhuang7",
	    "down"  : __DIR__"jingzhuang5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -36000);
	set("coor/y", -70400);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}