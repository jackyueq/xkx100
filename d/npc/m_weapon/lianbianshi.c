// ROOM lianbianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "���̶");
	set("long", @LONG
�����������Ŷ��Ĵ���ֱ޵ĵط������ڻ������̵ĸ��̲�ϡ���
Ȼ��������һ��Ư����̶ˮ���������˲��ò���̾����Ȼ�Ĺ��񹤡�
̶������վ��һλ�������Ů�����а�����һ�ѿ��Ƽ��Ƿ�����ذ�ף�
�����Ŀ��������̶ˮ����
LONG );
	set("exits", ([
		"north" : "/d/xingxiu/nanjiang3",
	]));
	set("objects", ([
		__DIR__"npc/shibian" :1,
	]));
	set("coor/x", -41010);
	set("coor/y", 8950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
