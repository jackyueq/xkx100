// /yubifeng/tongdao1.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
ɽ��ͨ�����������ۣ�����ת�˼����䣬����δ����ͷ�����е���
��ǧ�겻���ļ������Щ�����ı����絶�������ͻ����
LONG );
	set("exits", ([
		"up"   : __DIR__"yuanfengding",
		"east" : __DIR__"tongdao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6100);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
