//Room: /d/dali/zhangfang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�˷�");
	set("long",@LONG
�����������������˷�������ÿ������׳��룬�������ģ�
ȫ�����ﾭ�֣������Ҷ����˵�нٺ�ʹͣ����ڶ����鷳��ࡣ
����ȴ����û�������
LONG);
	set("objects", ([
	   __DIR__"npc/huo": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"wfdating",
	]));
	set("coor/x", -39010);
	set("coor/y", -70000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}