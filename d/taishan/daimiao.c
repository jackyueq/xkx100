// Room: /d/taishan/daimiao.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
̩ɽ��������Ƕ������񶫻��۾��ĵ��������ϵ������ιᴩ��
���š������š��ʰ��š����ܵ���޹��������ţ����ศ�Ժ���Ժ��
�����������������ƻ�Ժ���껨��Ժ��������׳����������۵����
�ɼ�������������ڷ���
LONG );
	set("exits", ([
		"north" : __DIR__"daizong",
		"south" : __DIR__"yaocan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
