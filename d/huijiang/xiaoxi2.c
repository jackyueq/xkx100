// Room: /d/huijiang/xiaoxi2.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ת�˼����䣬��һ�Ų��������д��˳�ȥ����ǰһƬ�����������
������һ�����ٲ���ˮ���Ľ����չ�ӳ�գ��ֳ�һ���ʺ磬���ܻ�����
��ӻ������䣬��ӳ�ڱ��̵ĺ�ˮ֮�У�����Ī����Զ���Ǵ�Ƭ��
��ƽԭ�ޱ��޼ʣ��������ȥ��������ӣ��ݵ��ϼ���ֻ�����ڱ��ܳ�
�ݡ�
LONG );
	set("outdoors", "huijiang");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xiangxiang" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"eastdown" : __DIR__"xiaoxi1",
		"north"    : __DIR__"byriver",
	]));
	set("coor/x", -50030);
	set("coor/y", 9010);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
