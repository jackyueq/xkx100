// Room: /d/huangshan/erxian.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�ഫ���������춼��ֻ�����㱳һ��·���˶���ʧ�㡣������־�̣�
��٩��λ��ʿ��һ��һ�䣬�����˰�ɽ�µ�����Ժ�ĵ�·������Ϊ����
���ˣ��������ڴˡ����Ϊ��������һ�������ߣ������޳������Ҳ�
һλ�ɷ���ǣ��ֳ����ƣ������������׿�ɽ�����ǻ�٩��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"jiyu",
	]));
	set("objects", ([
		__DIR__"obj/huang" : 1,
		__DIR__"obj/zhang" : 1,
	]) );
	setup();
	replace_program(ROOM);
}
