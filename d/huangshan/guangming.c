// Room: /d/huangshan/guangming.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�������ǵڶ��߷壬��Ϊ��γ��ַ�⣬���Ա���Ϊ������������
�������ƽ���������󣬹�����������������������������������ˮ
���ӣ�����һɫ���������ǿ��ճ������ƺ�����ѳ����������Ե�ɺϣ�
�����Կ����ѵ�һ���ķ�⡣
LONG
	);
	set("exits", ([ 
		"west"    : __DIR__"feilai",
		"southup" : __DIR__"lianhua",
	]));
	set("objects", ([
		__DIR__"npc/monk" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
