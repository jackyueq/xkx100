// Room: /d/taishan/ertian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ֽС������š��������ž������ȣ�¥���ӵ��������Ϫɽͻ
أ�������ɹ��ճ�������ϼ�����з����������չ����Զ���������ˣ�
����ɽ�³������������£���հΡΡ᷷壬��ɽ��������ïȪ�ɣ��³�
��գ���Ȼ�ɻ���
    һ��ĵ�ɽ���������ﶼ���ۼ��������������̩ɽ��һ�밡����
��ǰ���վ���ʮ���̣��ܶ��˶�������ԥ������
LONG );
	set("exits", ([
		"north"     : __DIR__"kuaihuosan",
		"southdown" : __DIR__"huima",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		CLASS_D("taishan")+"/tiansong" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 390);
	set("coor/y", 660);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
