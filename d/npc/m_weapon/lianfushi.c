// ROOM lianfushi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ��");
	set("long", @LONG
�����������Ŷ��Ĵ��츫ͷ�ĵط����������ܲ��Ĵ����С�����
��һ��СС�յأ�����һ���ܼ�ª����¯�ͷ��䣬�Ա�һ��������
�����䣬˫Ŀȫ���ע����¯����ɫ�Ļ��硣
LONG );
	set("exits", ([
		"south" : "/d/heizhao/shanlu3",
	]));
	set("objects", ([
		__DIR__"npc/shifu" :1,
	]));
	set("coor/x", -4000);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
