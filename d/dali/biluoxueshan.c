//Room: /d/dali/biluoxueshan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ѩɽ");
	set("long",@LONG
����һƬ��ѩɽ֮�У��˵�ֻ�ǰ�ɽ����ȴ�Ѿ���ѩ��������
��̹��ˡ���ͷ��ȥ�����׵ķ���������У����Ҳ�����ر����䡣
�ɴ����ϵ�ɽ�������������ټ���ֻ���°��ɵ�ɽ��������ľ������
�������޺��е������ˡ��򶫲�Զ��һ������������ڳ�ɽ����֮��
�����һƬ�ȵء�
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "eastdown"   : __DIR__"shanlu2",
	    "westdown"   : __DIR__"lushuieast",
	]));
	set("no_clean_up", 0);
	set("coor/x", -70000);
	set("coor/y", -70000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}