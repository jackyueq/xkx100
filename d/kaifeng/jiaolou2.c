// /kaifeng/jiaolou2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥��ƽʱפ���������ĵط���һ��ֻ��¥�Ķ��˹��˸�������
�ơ���ҹ����ֵ�ء��Ӵ�����������ȸ�ţ������Ƕ���֣�����ĿԶ����
������¥�����Ǵ�ý�ɽ��
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"zhuque",
		"eastdown" : __DIR__"eroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
