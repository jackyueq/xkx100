// Room: /d/suzhou/shiyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long",@long
����һ��ͻ��ƽ�صľ�ʯ����Ϊ��ʯ������ʯ��������š�������
�������֣����ϰ��۴�����˵�Ƿ������ʩ��ʯ��������̫��ʯ���µ�
��ӡ����ʯ���Ը��ӣ�����������ˮ�ݡ�
long);
	set("outdoors", "suzhou");
	set("objects",([
		__DIR__"npc/ke" : 2,
	]));
	set("exits",([
		"southup" : __DIR__"lingyansi",
		"westdown" : __DIR__"shuiwa1",
		"eastdown" : __DIR__"shuiwa",
		"northdown" : __DIR__"yingxiaoting",
		"southwest" : __DIR__"mubei",
	]));
	set("coor/x", 900);
	set("coor/y", -1110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
