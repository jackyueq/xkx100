// Room: /d/suzhou/sdhyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long",@long
����ԭ���⹬������԰��ַ��԰���з������ʩ����ȡ�֣���Ϊ��
ɽ�����ۡ����滨�ء��صĶ���������������ר����ʩ������ױ֮�á�
������һ��������ɮ�޿����ǻ��������ں�����ˮ��ȡ��ˡ�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"west"     : __DIR__"zhijijing",
		"east"     : __DIR__"wuwangjing",
		"eastdown" : __DIR__"lingyanta",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
