// Room: /d/xingxiu/xxroad3.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����һ����̫�ߵ�Сɽ��ɽ����ȥ����������� (sky)Ʈ�ż��䵭
���İ��ơ�һȺ���㷢�����¸¡��Ľ�������ͷ�Ϸɹ�������ɽ�³���
�Ĳ�ԫ�ϱ���ϡ�ɱ档���ǵľ�ͷ��һ����ΰ�Ĺذ���·����һ������
֮�Ͽ����״�(poem)��
LONG );
	set("exits", ([
		"westdown"  : __DIR__"jiayuguan",
		"northdown" : "/d/yongdeng/yongdeng",
		"southdown" : __DIR__"xxroad2",
	]));

	set("item_desc", ([ 
"poem" : "�±��Ͽ���һ����ƽ�֣�

  ��  ��  ��  ��  ��  ��  ��  ��
  ʱ  ��  ��  ��  ָ  ��  ��  ��
  ��  ��  ��  ɽ  ��  ��  ��  ��
  ��  ӧ  ��  ��  ��  ��  ��  ��
  ��  ��  ��  ��  ��  ��  ��  
  ��  ��  ��  ��  ��  ��  
                      ��

�������Ǻú��ˣ�
\n",
"sky" : "
                              \\/             \\/
                   /*=*         \\/       \\/
                   (*=*=)         \\/  \\/
               {/*=**=/            \\/
                         __
                        /\\.\\_   
               /\\  /\\  /  ...\\   /\\
              / .\\/ .\\/    .. \\_/ .\\
             /  ..\\  /    ... . \\  .\\      /\\
            /͹͹͹\\/͹͹͹. ..͹\\͹.\\    / .\\  
  _͹͹͹͹/     ..͹     ͹͹͹..\\__.\\͹/  ..\\_͹͹͹͹͹͹͹͹͹͹͹͹_\n\n"
]));

	set("no_clean_up", 0);
	set("outdoors", "silu");

	set("coor/x", -9600);
	set("coor/y", 3000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
