// Room: /d/taishan/doumo.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "��ĸ��");
	set("long", @LONG
��ĸ��Ϊ̩ɽ�ŵ��ۡ���������Ȫ�壬������Ȫˮ������ɽϿ�ƹ�
��ע��Ϫ����������Ȫ�ۡ��������̵������־���֮�ϣ��������š���
�����������ס�֣��뱱������֮ĸ����������ѹ�����������Ժ����
�ƶ�ĸ��������ԭ�붷ĸ���׳�ǧ��ǧ�۷𡣽��õز�����ͭ��
    ����ǰ����һ��ɽ·������һ�㶼����������Ϊ��Ϣ������ĵ���
�Ѿ���̩ɽ�ڽ�������ɽΪ�ߣ�������������ȥ����ʯ������
LONG );
	set("exits", ([
		"southeast" : __DIR__"feilong",
		"southwest" : __DIR__"fengyue",
		"northup"   : __DIR__"tianshen",
		"eastup"    : __DIR__"jingshi",
		"southdown" : __DIR__"taohua",
	]));
	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));
	set("coor/x", 400);
	set("coor/y", 600);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
