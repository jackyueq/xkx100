// Room: /d/huangshan/wenzhu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����Ժ");
	set("long", @LONG
�ഫ�������ŷ�ʦ�������������������������Խ�����Ժ��������
��ʢ��һʱ����ϧ������������а�������������ս���꼰����Ժ����
�дӴ�һ�겻�����������Կɴ�ǽ�ڵĺۼ�ң�뵱��һս�Ĳ��ҡ�
LONG
	);
	set("exits", ([ 
		"southwest" : __DIR__"yingke",
		"east"      : __DIR__"yixian",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
