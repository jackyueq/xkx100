// /yubifeng/tongdao2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
��Ѩ������խ����ù�����з���ͨ�������е�����ǧ�겻���ļ�
������Щ�����ı����絶�������ͻ������ʱͷ��ײ���˼����ǣ���
�����ۡ�
LONG );
	set("exits", ([
		"north" : __DIR__"shimen",
		"west"  : __DIR__"tongdao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
