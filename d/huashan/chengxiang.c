 // chengxiang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "������ɽ��");
	set("long", @LONG
��˵��ɽ��ʥĸ������һ�������������������Ϊ�򸾣����ֶ���
�񷴶����ǽ�ϣ�����ѹ�ڻ�ɽ�£����Ķ��ӳ��㳤����ø���������
ɽ���ȳ���ĸ�ס��Ա���һ���м��ѿ��Ĵ�ʯ�����ø���������һ�㣬
��������ʯ����˵���ǳ�����ɽ��ĸ�ĵط���
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"westup"   : __DIR__"lianhua",
		"eastdown" : __DIR__"lianpath2",
	]));

	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("coor/x", -900);
	set("coor/y", 180);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
