//Room: /d/dali/yuhuayuan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����԰");
	set("long",@LONG
�����Ǵ�����ʹ�������԰�����ԵĻ��������涷�ޣ�������
һ��Сˮ�أ�ɽ����������Ȫˮ�ͻἯ�����
��ֻ�ɺ���ˮ��ץ�㣬һ���������˵����ӣ�
�����ǻ��ȣ�������ǰ�
LONG);
	set("objects", ([
	   __DIR__"npc/xianhe": 1,
	]));
	set("outdoors", "daligong");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"hualang",
	    "south"  : __DIR__"qiandian",
	]));
	set("coor/x", -40010);
	set("coor/y", -70970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}