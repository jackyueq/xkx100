// clone/shop/shang-ling.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(NOR + WHT "����" NOR, ({ "shang ling", "shang", "ling" }));
	set_weight(1);
  if( clonep() )
      set_default_object(__FILE__);
  else 
  {
		set("long", NOR + WHT "����һ�ź�׽�ߵ�ͨ����ɴ������䷢��\n" NOR);
		set("unit", "��");
		set("value", 5);
		set("material", "paper");
		set("no_sell", "����ͷ����ѳԷ��ļһ�Ҳ������Ǯ��");
		set("no_drop",1);
	}
	setup();
}

void init()
{
	add_action("do_stock", "stock");
	add_action("do_unstock", "unstock");
}

int do_stock(string arg)
{
	object obj, me, goods;
	int amount, value,i,prize;
	mapping all_goods;
	string beishu, *args;

	me = this_player();

	if (! me->query("is_vendor"))
		return notify_fail("ֻ�д�����ҵ���˲��ܰ�̯��\n");
	if (! present("shang ling", me))
		return notify_fail("��δ�������������ң�С��Ϊ�\n");
	if (! me->query_temp("on_baitan"))
		return notify_fail("������Ȱڸ�̯λ(baitan)���ܶ��ۻ��\n");
	if (! arg) return notify_fail("ָ���ʽ��stock <����> <ԭֵ����>\n");

	i = sizeof(args = explode(arg, " "));

	i--;
	if (! sscanf(args[i], "%d", amount)) amount = 0;
	else arg = replace_string(arg, " " + amount, "");

	if (! (goods = present(arg, me)) || ! objectp(goods))
		return notify_fail("�����ϲ�û��������\n");

	if (goods->is_character()) return notify_fail("�㲻�ܷ������\n");
	if (goods->query("money_id"))
		return notify_fail("������ǮҲ�������ۣ�\n");
	if (goods->query("id") == "shang ling")
		return notify_fail("���ⶫ�����ˣ��㿿ʲô���Է���\n");
//	if (goods->is_item_make())
	if (goods->query("ownmake"))
		return notify_fail("�ⶫ���Ƕ������ģ�����û��Ըȥ��\n");
	if (sizeof(me->query("vendor_goods")) >= 10 && !wizardp(me))
		return notify_fail("��һ��ֻ�ܰ�ʮ�ֻ���������İɡ�\n");
	if (amount > 100)
	{
		if (!wizardp(this_player()) && amount > 10000000)
			return notify_fail("��Ʒ���ۼ۸��ܸ߹�1000���ƽ��ԭ�۵�һ�ٱ���\n");
		prize = amount;
	}
	if (!prize)
	{
		value = goods->query("base_value");

		if (! value) value = goods->query("value");
		if (amount)
		{ 
			value = amount * value;
			beishu = chinese_number((string)amount) + "����";
		}
		else
		{
			value = value/2;
			beishu = "���";
		}
	}
	else 
	{
		value = prize;
		beishu = MONEY_D->price_str(value);
	}

	if (! value) return notify_fail("�ⶫ����ֵǮ��û�˻�ȥ��ġ�\n");
	all_goods = me->query("vendor_goods");
	if (! all_goods) all_goods = ([ ]);

	all_goods[file_name(goods)] = value;
	me->set("vendor_goods", all_goods);
	message_vision(HIW "$N" HIW "��"+ goods->name(1) + HIW "��Ϊ" + beishu + HIW "����̯�ӿ�ʼ���ۡ�\n" NOR, me);
	return 1;
}

int do_unstock(string arg)
{
	object obj, goods, me = this_player();
	int i, amount, value, have_it = 0;
	mapping all_goods;
	string *goods_key, beishu;

	if (! me->query("is_vendor"))
		return notify_fail("ֻ�д�����ҵ���˲��ܰ�̯��\n");
	if (! me->query_temp("on_baitan"))
		return notify_fail("��Ŀǰ��û�а�̯��\n");
	if (! arg) return notify_fail("unstock <����>\n");
	if (! (goods = present(arg, me)))
		return notify_fail("�㲢û�ж���������\n");
	all_goods = me->query("vendor_goods");
	if (! all_goods) return notify_fail("�����ڲ�û�ж����κλ��\n");

	goods_key = keys(all_goods);

	for (i = 0; i < sizeof(goods_key); i++)
	{
		if (file_name(goods) == goods_key[i]) have_it = 1;
	}

	if (have_it) 
	{
		map_delete(all_goods, file_name(goods));
		message_vision(HIW "$N" HIW "��" + goods->name(1) + HIW"��̯�����������ˡ�\n"NOR, me);
	}
	else return notify_fail("�㲢û�ж���������\n");

	me->set("vendor_goods", all_goods);
	return 1;
}

int query_autoload()
{
	return 1;
} 
