// Room: /qingcheng/zoulang1.c
// Date: Aug. 10 1998 by Winder

inherit ROOM;
void create()
{
	set("short", "�ɷ�����");
	set("long", @LONG
�������ɷ��������ǰ���Ժ�����ȣ��ɷ�۸ߴ�ɽ������������
ȥ����ɽ��ţ��Ĺȷ��������챡��ʱʱ��ɢ�ڳ��ִ���֮�䡣�Թź�
�ƣ�����������ġ��������ڴ���ζ��
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"south" : __DIR__"zhongmen",
		"north" : __DIR__"caochang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}