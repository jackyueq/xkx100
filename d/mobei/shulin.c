// Room: /d/mobei/shulin.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�綯���֣���Ҷˢˢ���죬��Ƶ��¹��¼�ֻ�����ĵ��۾�������
�������ƶ���ͻȻ����ļ������ë���Ȼ����ͻأ��ֹͣ����������
�ǻ�ɽɽ�����������Ӿ��ǲ�ԭ��
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/zhucong" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"eastup" : __DIR__"hill1",
		"west"   : __DIR__"caoyuan1",
	]));
	set("coor/x", -220);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
