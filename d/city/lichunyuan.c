// Room: /city/lichunyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ��
�Ӿ�����������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ���������
����������Ů�˷�վ���Զ��㷢����Ц������Τ�����������¡�ǰǰ��
���к��ſ��ˡ���¥�ϴ���������������ε�������
LONG );
	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
                "/d/beijing/npc/mao18" : 1, 
	]));

	set("item_desc", ([
		"tu" :
"                                      ��        ��          ��             
                                    ����        ��          ��
      ����������  ���С�����        ����      ����          ����
    ����������    ����������  ����������  ������ء�  �������ة�


   ��       ��    ������                 ��                  ��
   ��       ��    ������       ������  ����                  ��
   �� ���Щ���    �����ੴ   ��������������          ��С�����
   ��   ������    ��  ��                 ��            ��  ����
	\n"]));
	set("exits", ([
		"east"  : __DIR__"beiliuxiang",
		"up"    : __DIR__"lichunyuan2",
	]));

	set("coor/x", 30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
